import {BrowserModule} from '@angular/platform-browser';
import {NgModule, Provider} from '@angular/core';
import {HttpModule} from '@angular/http';
import {CanActivate, RouterModule} from '@angular/router';

import {AppComponent} from './app.component';
import {HomeComponent} from './home/home.component';
import {GalleryGridService} from './services/gallery-grid.service';
import {AmexioWidgetModule} from 'amexio-ng-extensions';


@NgModule({
  declarations: [
    AppComponent,
    HomeComponent
  ],
  imports: [
    BrowserModule,
    HttpModule,
    AmexioWidgetModule,
    RouterModule.forRoot([
      {path: 'home', component: HomeComponent},
      {path: '', component: AppComponent, canActivate: [false]},
      {path: '**', component: AppComponent}
    ])
  ],
  providers: [
    GalleryGridService],
  bootstrap: [AppComponent]
})
export class AppModule {
}
