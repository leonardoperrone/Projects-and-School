import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';

import { AppComponent } from './app.component';
import { AppRoutingModule } from './/app-routing.module';
import { HomeComponent } from './pages/home/home.component';
import { AboutComponent } from './pages/about/about.component';
import { TechnologyDetailComponent } from './common/technology-detail/technology-detail.component';
import { SvgViewerComponent } from './common/svg-viewer/svg-viewer.component';
import { environment } from '../environments/environment';
import { AngularFireModule } from 'angularfire2';
import { AngularFireDatabaseModule } from 'angularfire2/database';
import { TechnologyService } from './services/technology.service';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { ToastrModule } from 'ngx-toastr';
import { LoaderComponent } from './common/loader/loader.component';
import { MatButtonModule, MatCheckboxModule, MatProgressSpinnerModule } from '@angular/material';
import { FooterComponent } from './common/footer/footer.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    AboutComponent,
    TechnologyDetailComponent,
    SvgViewerComponent,
    LoaderComponent,
    FooterComponent
  ],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    AppRoutingModule,
    NgbModule,
    AngularFireModule.initializeApp(environment.firebase, 'leonardo-web'),
    AngularFireDatabaseModule,
    MatButtonModule,
    MatCheckboxModule,
    MatProgressSpinnerModule,
    ToastrModule.forRoot()
  ],
  providers: [TechnologyService],
  bootstrap: [AppComponent]
})
export class AppModule {
}
